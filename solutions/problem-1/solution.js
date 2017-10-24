function multiples() 
{
var sum = 0, i = 1000;

while (i --) 
{
  if ( i % 3 === 0 || i % 5 === 0 ) 
   {
    sum += i;
   }
 }

return sum;
}
console.log(multiples(1000))
