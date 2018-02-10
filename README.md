# Harvard CS50 2018 Weekly Overview 

[Link to edX](https://courses.edx.org/courses/course-v1:HarvardX+CS50+X/course/)

## Week 0: Scratch
Link to play the game that I created : 
```javascript
https://scratch.mit.edu/projects/199032128/
```

## Week 1: C
[**hello.c**](https://github.com/jpacsai/HarvardX_CS50x/blob/master/Week%201/hello.c) : a program that prints out a simple greeting to the user, per the below.
```javascript
$ ./hello
hello, world
```

[**mario.c**](https://github.com/jpacsai/HarvardX_CS50x/blob/master/Week%201/mario.c) : a program that prints out a double half-pyramid of a specified height, per the below.
```javascript
$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```
[**credit.c**](https://github.com/jpacsai/HarvardX_CS50x/blob/master/Week%201/credit.c) : a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.
```javascript
$ ./credit
Number: 378282246310005
AMEX
```

[**caesar.c**](https://github.com/jpacsai/HarvardX_CS50x/blob/master/Week%201/caesar.c) : a program that encrypts messages using Caesar’s cipher, per the below.
```javascript
$ ./caesar 13
plaintext:  HELLO
ciphertext: URYYB
```
[**vigenere.c**](https://github.com/jpacsai/HarvardX_CS50x/blob/master/Week%201/vigenere.c) : a program that encrypts messages using Vigenère’s cipher, per the below.
```javascript
$ ./vigenere bacon
plaintext:  Meet me at the park at eleven am
ciphertext: Negh zf av huf pcfx bt gzrwep oz
```

## Week 2: Algorithms  

### [**bday.txt**](https://github.com/jpacsai/HarvardX_CS50x/blob/master/Week%203/bday.txt)  
In bday.txt, type the ASCII representation of Happy Birthday, translating its sheet music, above, to the machine-readable representation prescribed herein. You should find that the song begins with:

```javascript
D4@1/8
D4@1/8
E4@1/4
D4@1/4
G4@1/4
F#4@1/2
```
### [**helpers.c**](https://github.com/jpacsai/HarvardX_CS50x/blob/master/Week%203/helpers.c)  
In this file, there are three functions:

**duration**  
which should take as input as a string a fraction (e.g., 1/4) and return as an int a corresponding number of eigths (2, in this case, since 1/4 is equivalent to 2/8);

**frequency**  
which should take as input as a string a note formatted as
XY (e.g., A4), where X is any of A through G and Y is any of 0 through 8, or
XYZ (e.g., A#4), where X is any of A through G, Y is # or b, and Z is any of 0 through 8,
and return as an int the note’s corresponding frequency, rounded to the nearest integer; and

**is_rest**  
which should return true if its input, a string, represents a rest in our machine-readable format, otherwise false.


## Week 3: Memory
