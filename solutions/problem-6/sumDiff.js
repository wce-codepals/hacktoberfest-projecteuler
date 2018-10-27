function test() {
    var max = 100, x = 0, y = 0, i = 0, j = 0;
    (function Square'sSum() {
        while ( i <= max ) {
            x += Math.pow( i, 2 );
            i++;
        }
        document.write(x);
        return x;
    }());

    (function Sum'sSquare() {
        while ( j <= max ) {
            y += j;
            j++;
        }
        y = Math.pow( y, 2 );
        document.write(y);
        return y;
    }());

    return y - x;
}
