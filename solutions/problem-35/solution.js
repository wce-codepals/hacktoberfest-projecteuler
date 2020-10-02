var cpl = [2, 3, 5, 7];
for(il = 11; il < 1000000; il += 2){
  var icp = iscircleprime(il);
  if(icp == true){
    console.log(il);
    cpl.push(il);
  }
}
console.log(cpl.length);
function iscircleprime(nom){
  if(isprime(nom) == true){
    var dividants = 0;
    var circle = getrotation(nom);
    for(pi = 1; pi < circle.length; pi++){
      if(isprime(circle[pi]) == true){
        dividants += 1;
      }else{
        return false;
      }
    }
    if(dividants = circle.length - 1){
      return true;
    }else{
      return false;
    }
  }else{
    return false;
  }
}
function isprime(num){
  var divider = 0;
  for(i = 0; i < num + 1; i++){
    if(divider > 2){ return false;}
    if(Number.isInteger(num / i)){
      divider += 1;
    }
  }
  if(divider > 2){
    return false;
  }else{
    return true;
  }
}
function getrotation(number){
  var nar = [];
  var rotations = [number];
  var stringnumber = '' + number;
  arrify(stringnumber, nar);
  for(r = 0; r < nar.length - 1; r++){
    var buffer = stringnumber;
    for(nr = 1; nr < nar.length; nr++){
      nar[nar.length - nr] = nar[nar.length - nr - 1];
    }
    nar[0] = stringnumber[nar.length - r - 1];
    var toint = '';
    for(it = 0; it < nar.length; it++){
      toint += nar[it];
    }
    rotations.push(parseInt(toint));
  }
  return rotations;
}

function findex(num){
  var result = num;
  for(p = 1; p < num; p++){
    toadd = '' + p;
    result = multiply(result, toadd);
  }
  return result;
}
function digitsum(target){
  var result = 0;
  for(l = 0; l < target.length; l++){
    var toadd = parseInt(target[l]);
    result += toadd;
  }
  return result;
}
function square(stringnumber, number){
  var result = 1;
  var power = parseInt(number);
  for(o = 0; o < power; o++){
    result = multiply(result, stringnumber);
  }
  return result;
}
function multiply(a, b){
  var longstring = long(a, b);
  var result = long(a, b);
  var multiplier = parseInt(short(a, b));
  for(u = 1; u < multiplier; u++){
    result = add(result, longstring);
  }
  return result;
}
function add(a, b){
  var ar = [];
  var br = [];
  var rr = [];
  arrify(a, ar);
  arrify(b, br);
  var big = long(ar, br);
  var smol = short(ar, br);
  var pointer = 0;
  var lendiff = big.length - smol.length;
  var carry = 0;

  for(i = 0; i < big.length; i++){
    if(i >= lendiff){
      rr.push(parseInt(big[i]) + parseInt(smol[i - lendiff]));
    }else{
      rr.push(big[i]);
    }
  }
  for(i = 0; i < rr.length; i++){
    rr[i] = parseInt(rr[i]);
  }
  for(g = 0; g < big.length; g++){
    for(i = 0; i < rr.length; i++){
      if(i != 0){
        if(rr[i] >= 10){
          rr[i] = rr[i] - 10;
          rr[i - 1] += 1;
        }
      }else{
        if(rr[0] >= 10){
          rr[0] = rr[0] - 10;
          rr.push(rr[rr.length - 1]);
          for(h = rr.length - 1; h > 0; h--){
            rr[h] = rr[h - 1];
          }
          rr[0] = 1;
        }
      }
    }
  }
  var result = '';
  for(i = 0; i < rr.length; i++){
    result += rr[i];
  }
  return result;
}
function arrify(string, array){
  for(i = 0; i < string.length; i++){
    var char = string.charAt(i);
    array.push(char);
  }
}
function long(x,y){if(x.length > y.length){return x;}else{return y;}}
function short(x,y){if(x.length > y.length){return y;}else{return x;}}
function max(x,y){if(x > y){return x;}else{return y;}}
function min(x,y){if(x > y){return y;}else{return x;}}
