var x = 1;
var True = true;
while(True) {
  var works = true;
  for(i = 1; i < 21; i++){
    if(x % i != 0) {
      works = false;
      x += 1;
      break;
    }
  }
  if(works) {
    console.log(x);
    break;
  }
}
