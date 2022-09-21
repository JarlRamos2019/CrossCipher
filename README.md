# CrossCipher
Encryption algorithm that uses a unique plotting diagram based on inserting characters at points of a cross.
The data is loaded into arrays using an algorithm based around a cross where characters will be "inserted" into
the cross points. Each point will be an array holding encrypted data. A sample cross for the string "Kimberly"
is given below:

* c4 = "by"     * c1 = "Ke"
  *           *
    *       *
      *   *
        *
      *   *  
    *       *
  *           *
* c3 = "ml"     * c2 = "ir"

Per the diagram, the first array, c1, starts at the rightmost part of the cross and goes clockwise. The arrays will
be loaded in a clockwise fashion starting at c1, where one character from the loaded data will be added to the array
and the next character will be added to the next array and so on. Once the program is finished loading the arrays
then it will output the encrypted data. This process starts with the leftmost array c4 and will go counter-clockwise.
All the array's contents that were loaded by the last procedure will be outputted at once. The outputted string for the
string "Kimberly" is given below:

by ml ir Ke
