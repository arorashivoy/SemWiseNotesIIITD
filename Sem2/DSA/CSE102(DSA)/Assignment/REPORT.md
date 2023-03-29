# Huffman Coding

## Report
### By - Shivoy Arora

---
#### Question 1
Are you using min-heap in your implementation?

**A.** Yes

---
#### Question 2
What is the size of the compressed file after compressing the sample input file provided
with the assignment?

**A.** 
Size of the original file :- 10 KB
Size of the compressed file :- 3 KB

---
#### Question 3
Describe the format of the metadata that is stored in the compressed file.

**A.** The metadata is the first line of the compressed file
* The first line contains space-separated characters and number
  * The first number is the number of bits in the encoded file
  * Then, there are space-separated pairs of character with there frequency
  * `Bits char1 freq1 char2 freq2 ... charN freqN`
* From the second line the decoded message is present
