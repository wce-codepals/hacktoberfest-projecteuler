#include <array>
#include <iostream>
#include <vector>

int main() {
  /// So the problem is to find all the losing configurations of the game,
  /// where each turn a player can remove an equal number of stones from
  /// one or more of the three columns

  /// Given the deterministic nature of the game, each configuration
  /// must either be a winning configuration or a losing one, because both
  /// players playing optimally will always result in one player winning or
  /// losing deterministically based on the initial configuration

  /// A winning configuration is one in which the currently playing player
  /// is guaranteed to win

  /// And a losing configuration as one that, regardless of the player's move,
  /// results in the the second player always winning

  /// Let's try to define a winning configuration, and then define a losing
  /// configuration based on what we find out about winning configurations

  /// There are a set of trivial winning configurations, where the state is
  /// some permutation of (N, 0, 0), (N, N, 0), or (N, N, N) for some N
  
  /// Any move from a losing configuration must necessarily be a winning combination
  /// and for any winning configuration aside from the final move there must exist a losing configuration that is reachable in one move

  /// Thus, to solve this problem, can we try to mark all the trivial winning configurations,
  /// then mark all the points that can reach those losing configurations as winning configurations,
  /// and repeat until the entire space is populated

  /// If we think of this on a 2-D grid (y increases up, x increases to the right),
  /// you'll start to notice a pattern
  /// The first row and column, along with the diagonal that intersects (0, 0)
  /// all are winning configurations except for (0, 0), since you'll already have lost
  /// if you end up there
  ///
  /// +          +
  /// +         +
  /// +        +
  /// +       +
  /// +      +
  /// +     +
  /// +    +
  /// +   +
  /// + +
  /// ++
  /// -++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// (2, 1) and (1, 2) are the first two losing configurations because all the
  /// the points down, and to the left of them are winning configurations
  /// After setting them to losing configurations, we can fill in the space up,
  /// to the right, and along the diagonal that intersects them
  /// After filling in all that space, we can see that the next two losing configurations
  /// are at (3, 5) and (5, 3)
  /// 
  /// +++      +++
  /// +++     +++
  /// +++    +++
  /// +++   +++
  /// +++  +++
  /// +++0+++
  /// ++++++
  /// +++++0
  /// +-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// ++-++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// -++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// After filling in the space again, we see the next points are at (4, 7)
  /// and (7, 4)
  /// 
  /// ++++ +  +++++
  /// ++++ + +++++
  /// ++++ ++++++
  /// ++++0+++++
  /// +++++++++
  /// +++-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// +++++++0
  /// +++++-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// +-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// ++-++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// -++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Followed by (6, 10) and (10, 6)
  /// ++++++0+++++++
  /// +++++++++++++
  /// ++++++++++++
  /// ++++-++++++
  /// ++++++++++0
  /// +++-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// +++++++-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// +++++-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// +-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// ++-++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// -++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// As you can see, in the 2-D case each x and y coordinate corresponds to
  /// one losing configuration, and each one is on a distinct diagonal

  /// Extending this idea into 3-D, we can try to calculate the position of each
  /// losing configuration by starting with a known losing configuration and finding the
  /// next set of losing configurations by seeing where the next closest empty
  /// points are

  /// Let's try to formalize the relationship between the next set of losing
  /// configurations given the current set of losing configurations (namely that the last set of
  /// losing configurations can't be reached by the current set):
  /// P_next = (arg_(x, y, z) min(x + y + z) where
  //            (\not \exists p \in P_cur where p_x < x and p_y = y and p_z = z) and
  //            (\not \exists p \in P_cur where p_x = x and p_y < x and p_z = z) and
  //            (\not \exists p \in P_cur where p_x = x and p_y = y and p_z < z) and
  //            (\not \exists p \in P_cur where (p_x - p_y = x - y) and p_z = z) and
  //            (\not \exists p \in P_cur where (p_y - p_z = y - z) and p_x = x) and
  //            (\not \exists p \in P_cur where (p_x - p_z = x - z) and p_y = y) and
  //            (\not \exists p \in P_cur where (x - y = p_x - p_y) and (z - y = p_z - py)))
  /// The minimization part of it is kind of a hand wavey guess

  /// So now it's a matter of finding an order of traversing and testing all the points so that
  /// we'll reach the losing configurations in an order that prevents us from hitting
  /// any false positives, giving us an O(n^5) solution (we're searching O(n^3) points
  /// and have to test against O(n^2) points)
  /// One likely possible solution is to follow the set of planes along x + y + z = n,
  /// increasing n each iteration
  /// Let's try that out for n = 100 to sanity check all our above assumptions

  struct Point {
    int x, y, z;
  };

#if 0
  {
    std::vector<Point> losing;
    std::vector<Point> foundPoints;
    losing.push_back(Point{0, 0, 0});
    long total = 0;
    int n = 0;
    const int N = 100;

    while (n <= 3*N) {
      foundPoints.clear();
      // TODO: optimize these constraints so that the loop bounds
      // more closely match the actual boundraries
      for (int x = 0; x <= n && x <= N; x++) {
        for (int y = 0; y <= n - x && y <= N; y++) {
          int z = n - x - y;
          if (z > N) {
            continue;
          }

          bool isValid = true;
          for (auto &p: losing) {
            isValid = isValid &&
              !(p.x < x && p.y == y && p.z == z) &&
              !(p.x == x && p.y < y && p.z == z) &&
              !(p.x == x && p.y == y && p.z < z) &&
              !((p.y - p.z == y - z) && p.x == x) &&
              !((p.x - p.z == x - z) && p.y == y) &&
              !((p.x - p.y == x - y) && p.z == z) &&
              !((p.x - p.y == x - y) && (p.y - p.z == y - z));
            if (!isValid) {
              break;
            }
          }

          if (isValid) {
            foundPoints.push_back(Point{x, y, z});
          }
        }
      }
      for (auto &point: foundPoints) {
        losing.push_back(point);
        // Only add the ones Project Euler cares about to the total
        if (point.x <= point.y && point.y <= point.z) {
          total += n;
        }
      }
      std::cout << n << " " << total << std::endl;
      ++n;
    }
    std::cout << total << std::endl;
  }
  // 173985
#endif
  /// So we have something that solves it for N = 100!
  /// Unfortunately, this takes a few seconds to run, so running it for N = 1000
  /// would take on the order of a days to weeks thanks to the O(n^5) run time
  
  /// We need to find a more efficient way of determining whether a point is
  /// losing configuration, basically a better lookup system than comparing
  /// it against all previous losing configurations
  /// There's several approaches that come to mind here, but I'm gonna choose
  /// the one that seems to have okay trade offs between complexity and memory
  /// usage
  /// This is allocating an array of booleans for each axis (one for each of
  /// the seven tests above) and storing whether a losing configuration has
  /// already been found for that given axis
  /// Then checking each point would only consist of seeing if a losing configuration
  /// that matches the given point on any of the axes hasn't already been found,
  /// because if one has, then that point would be a winning configuration
  /// We have to use dynamically sized vectors instead of arrays because
  /// the arrays cause a segfault (probably from stack overflow) if we try to
  /// use them for N = 100
  const int N = 1000;
  // Just a simple macro to avoid a lot of extra typing
  #define I(x, y) x, std::vector<bool>(y, false)
  std::vector<std::vector<bool>> xy(I(N+1, N+1)), xz(I(N+1, N+1)), yz(I(N+1, N+1));
  std::vector<std::vector<bool>> xDiag(I(2*N+1, N+1)), yDiag(I(2*N+1, N+1)), zDiag(I(2*N+1, N+1));
  std::vector<std::vector<bool>> diag(I(2*N+1, 2*N+1));

  long total = 0;
  int n = 0;

  // add the initial losing point, (0, 0, 0)
  xy[0][0] = true;
  xz[0][0] = true;
  yz[0][0] = true;
  xDiag[0-0+N][0] = true;
  yDiag[0-0+N][0] = true;
  zDiag[0-0+N][0] = true;
  diag[0-0+N][0-0+N] = true;

  while (n <= 3*N) {
    // TODO: optimize these constraints so that the loop bounds
    // more closely match the actual boundraries
    for (int x = 0; x <= n && x <= N; x++) {
      for (int y = 0; y <= n - x && y <= N; y++) {
        int z = n - x - y;
        if (z > N) {
          continue;
        }

        bool isValid = !xy[x][y] && !xz[x][z] && !yz[y][z] &&
          !xDiag[y - z + N][x] && !yDiag[x - z + N][y] &&
          !zDiag[x - y + N][z] && !diag[x - y + N][y - z + N];

        if (isValid) {

          // update all the arrays
          xy[x][y] = true;
          xz[x][z] = true;
          yz[y][z] = true;
          xDiag[y - z + N][x] = true;
          yDiag[x - z + N][y] = true;
          zDiag[x - y + N][z] = true;
          diag[x - y + N][y - z + N] = true;

          if (x <= y && y <= z) {
            total += n;
          }
        }
      }
    }
    // std::cout << n << " " << total << std::endl;
    ++n;
  }
  std::cout << total << std::endl;

  return 0;
}
