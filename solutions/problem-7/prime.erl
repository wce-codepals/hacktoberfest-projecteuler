-module(prime).
-export([check/2]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Language: Erlang              %
% Usage:                        %
% erl                           %
% > c(prime).                   %
% > prime:check(10001, 12000).  %
% > prime:check(10001, 120000). %
%                   |  |        %
% number to check <-'  '-> max  % 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

gen_primes(N) when N>1 -> 
    [X || X <- lists:seq(2,N), (length([Y || Y <- lists:seq(2, trunc(math:sqrt(X))), ((X rem Y) == 0)]) == 0)];
gen_primes(_) -> [].

check(Nth, Max) ->
    case (L = length(gen_primes(Max))) < Nth of
        true -> 
            io:format("The generated prime numbers are not enough (~p). Increase the maximum value!\n", [L]);
        false ->
            lists:nth(Nth, gen_primes(Max))
    end.
