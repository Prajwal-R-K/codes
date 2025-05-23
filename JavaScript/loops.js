for(let i=0;i<6;i++){  //Dont use const
    console.log(i);
}

const a=[7,23,3];
// for(let i in a){
//     console.log(a[i]);
// }

// for(let i of a){
//     console.log(i);
// }

const b={x:12,y:"hello",z:87} ; // Object is not iterable(SO for of loop wont work)
// for(const/*let*/ i in b){
//     console.log(i,b[i]);
// }

// for(let i of b){
//     console.log(i);
// }

let c="Language";
// for(let [i,j] of c){
//     console.log(i);
// }

const d=[23,24,25,26] 
/*//d.forEach(myfunc); --- ReferenceError: Cannot access 'myfunc' before initialization
const myfunc = function(value, index, array) {
    console.log(value, index, array);
};
d.forEach(myfunc); */


// d.forEach(myfunc1);
// function myfunc1(value, index, array) {
//     console.log(value, index, array);
// }

let i=0
// while (i < 10) {
//    console.log("The number is " + i);
//     i++;
//   }

// do {
//     console.log("The number is " , i);
//     i++;
//   }
//   while (i < 10);


