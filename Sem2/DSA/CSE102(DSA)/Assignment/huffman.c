// 
// huffman.c
// By - Shivoy Arora
// 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


////////////////// Declaring structures //////////////////
/**
 * @brief data-structure for an element in the array
 *
 */
typedef struct element {
    char val;
    long int freq;
    struct element* left;
    struct element* right;
} ele;


/**
 * @brief heap data-structure using arrays
 *
 */
typedef struct heap {
    ele** arr;
    int heapLen;
    int arrLen;
    int size;
} heap;


/**
 * @brief structure to store the character and its code
 *
 */
typedef struct Code {
    char val;
    char code[16];
} Code;


/////////////////// Global Variables ///////////////////
Code charCodes[256];        // List of the code of each character
int charCodesIndex = 0;     // Index of the charCodes

int head = 0;               // Queue head
int tail = 0;               // Queue tail
int size = 64;              // Size of the queue

////////////////// Helper Functions //////////////////
/**
 * @brief to swap memory addresses of two elements
 *
 * @param a first element
 * @param b second element
 */
void swap(ele** a, ele** b) {
    ele* tmp = *a;
    *a = *b;
    *b = tmp;
}


/**
 * @brief Check if the character is in element array
 *
 * @param arr element array
 * @param n length of the array
 * @param val character
 * @return 1 if in else 0
 */
int find(ele* arr[], int n, char val) {
    for (int i = 0; i < n; i++) {
        if (val == arr[i]->val) {
            return i;
        }
    }

    return -1;
}

/**
 * @brief Find the encrypted code of a character
 *
 * @param arr list of codes of the characters
 * @param val character whose code is to be found
 * @return index at which the value is stored in the arr
 */
int findCode(Code arr[], char val) {
    for (int i = 0; i < 256 && arr[i].val != '\0'; i++) {
        if (arr[i].val == val) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief print the huffman codes
 *
 * @param e binary tree of the elements
 * @param code the code of the current root
 */
void printCode(ele* e, char code[]) {
    char codeL[25];
    char codeR[25];

    if (e == NULL) {
        return;
    }

    if (e->val != '\0') {
        printf("%c: %s\n", e->val, code);

        // Adding the code to the charCode array
        Code c;
        c.val = e->val;
        strcpy(c.code, code);
        charCodes[charCodesIndex] = c;
        charCodesIndex += 1;
    }

    strcpy(codeL, code);
    strcpy(codeR, code);

    strcat(codeL, "0");
    strcat(codeR, "1");

    printCode(e->left, codeL);
    printCode(e->right, codeR);
}


/**
 * @brief Create a Element object
 *
 * @param val value of the element
 * @param freq frequency of the element
 * @return root of the element binary tree
 */
ele* createElement(char val, long int freq) {
    ele* e = (ele*)malloc(sizeof(ele));
    e->val = val;
    e->freq = freq;
    e->left = NULL;
    e->right = NULL;

    return e;
}


/**
 * @brief Find length of the string
 *
 * @param str given string
 * @return length of the string
 */
int lenStr(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

/**
 * @brief Convert a binary number to int
 *
 * @param code binary number in the form of a string
 * @return decimal equivalent of code
 */
int binConv(char code[]) {
    int num = 0;
    for (int i = 0; i < 8; i++) {
        if (code[i] == '\0') break;
        else if (code[i] == '1') {
            num += pow(2, 8 - i - 1);
        }
    }

    return num;
}


////////////////// Queue //////////////////
/**
 * @brief push an element to a queue
 *
 * @param q queue
 * @param val value to be pushed
 * @return 1, if queue is full else 0
 */
int push(char q[], char val) {
    q[tail] = val;
    tail += 1;
    tail %= size;

    if (tail == head)
        return 1;
    return 0;
}

/**
 * @brief pop an item from queue
 *
 * @param q queue
 * @return removed element, if successful else '\0'
 */
char pop(char q[]) {
    if (head == tail)
        return '\0';

    char tmp = q[head];
    head += 1;
    head %= size;

    return tmp;
}

/**
 * @brief insert a value to the front of the queue
 *
 * @param q queue
 * @param val value to be inserted
 */
void insertQ(char q[], char val) {
    head -= 1;
    if (head < 0) {
        head = size - 1;
    }
    q[head] = val;
}


////////////////// Min Heap Functions //////////////////
/**
 * @brief Create an empty min heap of size length
 *
 * @param size size of the min heap
 * @return empty min heap
 */
heap* createMinHeap(int size) {
    heap* H = (heap*)malloc(sizeof(heap));

    H->arr = (ele**)malloc(sizeof(ele*) * (size + 1));
    H->heapLen = 0;
    H->arrLen = 0;
    H->size = size;

    return H;
}

/**
 * @brief heapify the array
 *
 * @param arr array of element structure
 * @param n size of the array
 * @param i index at which to heapify
 */
void heapifyAt(ele* arr[], int n, int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;

    if (left <= n && arr[smallest]->freq > arr[left]->freq) {
        smallest = left;
    }
    if (right <= n && arr[smallest]->freq > arr[right]->freq) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapifyAt(arr, n, smallest);
    }
}

/**
 * @brief make node i follow the heap protocol
 *
 * @param H heap
 * @param i index of the array
 */
void minHeapify(heap* H, int i) {
    heapifyAt(H->arr, H->heapLen, i);
}

/**
 * @brief build a min heap from an array
 *
 * @param H heap struct whose array is to be converted to min heap
 */
void buildMinHeap(heap* H) {
    int i;
    int n = H->arrLen;
    H->heapLen = H->arrLen;

    for (i = n / 2; i >= 1; i--) {
        minHeapify(H, i);
    }
}

/**
 * @brief Get the element with the most priority
 *
 * @param H heap structure
 *
 * @returns removed element
 */
ele* extractMinHeap(heap* H) {
    ele* tmp = H->arr[1];
    H->arr[1] = H->arr[H->heapLen];
    H->arr[H->heapLen] = tmp;

    H->heapLen -= 1;

    minHeapify(H, 1);

    return tmp;
}

/**
 * @brief make the value at index satisfy min heap protocol
 *
 * @param arr arr of the heap
 * @param index index to be checked
 */
void insertAt(ele* arr[], int index) {
    if (index == 1)
        return;

    int parent = index / 2;
    if (arr[parent]->freq > arr[index]->freq) {
        swap(&arr[parent], &arr[index]);
        insertAt(arr, parent);
    }
}

/**
 * @brief inserting an element in the heap
 *
 * @param H heap structure
 * @param val value to be inserted in H
 */
void insert(heap* H, ele* val) {
    int n = H->heapLen;

    H->arr[n + 1] = val;
    insertAt(H->arr, n + 1);
    H->arrLen += 1;
    H->heapLen += 1;
}


////////////////// Huffman Coding //////////////////
/**
 * @brief To create the Tree structure for compression
 *
 * @param arr array that stores frequency of each character
 * @param arrIndex length of the array arr
 *
 * @returns Tree structure of the code
 */
ele* huffman(ele* arr[], int arrIndex) {
    // Creating min heap
    heap* H = createMinHeap(arrIndex);
    H->arrLen = arrIndex;
    for (int i = 0; i < arrIndex; i++) {
        H->arr[1 + i] = arr[i];
    }

    buildMinHeap(H);

    // Huffman coding
    ele* a, * b, * c;
    while (H->heapLen != 1 && H->heapLen != 0) {
        a = extractMinHeap(H);
        b = extractMinHeap(H);

        c = createElement('\0', (a->freq + b->freq));
        c->left = a;
        c->right = b;

        insert(H, c);
    }

    return H->arr[1];
}


////////////////// Compressing File //////////////////
/**
 * @brief Write the compressed data to the file
 *
 * @param fin decompressed file
 * @param fout compressed file to be made
 * @return number of bits in the encoded data
 */
int encode(FILE* fin, FILE* fout) {
    char a;
    char encrypted[9] = "00000000";
    char buffer[65];
    int encryptedIndex = 0;
    int bufferIndex = 0;
    int i = 0;
    long int bitsWritten = 0;

    // Setting buffer to empty
    for (int i = 0; i < 65; i++) {
        buffer[i] = '\0';
    }

    while (feof(fin) == 0) {
        a = '\0';
        fscanf(fin, "%c", &a);

        int charIndex = findCode(charCodes, a);
        if (charIndex == -1) {
            break;
        }

        // Copying the code the an 8-bit string and if full then a buffer
        i = 0;
        while (charCodes[charIndex].code[i] != '\0') {
            if (encryptedIndex >= 8) {
                buffer[bufferIndex] = charCodes[charIndex].code[i];
                bufferIndex += 1;
            }
            else {
                encrypted[encryptedIndex] = charCodes[charIndex].code[i];
                encryptedIndex += 1;
            }
            i += 1;
        }

        // writing to the file
        i = 0;
        if (encryptedIndex >= 8) {
        encryptedFull:
            fprintf(fout, "%c", binConv(encrypted));

            bitsWritten += 8;
            encryptedIndex = 0;

            while (buffer[i] != '\0') {
                if (encryptedIndex == 8) {
                    goto encryptedFull;
                }
                encrypted[encryptedIndex] = buffer[i];
                encryptedIndex += 1;

                i += 1;
            }

            // Setting buffer to empty
            for (int i = 0; i < 65; i++) {
                buffer[i] = '\0';
            }
            bufferIndex = 0;
        }
    }

    // writing the partially filled encrypted str
    fprintf(fout, "%c", binConv(encrypted));

    bitsWritten += encryptedIndex;
    return bitsWritten;
}

/**
 * @brief write frequency of each character to the table file
 *
 * @param fTable pointer of the table file
 * @param arr array that contains frequency of each character
 * @param bitsWritten number of bits written to the header file
 */
void tableWrite(FILE* fTable, ele* arr[], long bitsWritten) {
    fprintf(fTable, "%ld ", bitsWritten);

    for (int i = 0; i < 256 && arr[i]->val != '\0'; i++) {
        fprintf(fTable, "%c %ld ", arr[i]->val, arr[i]->freq);
    }
    fprintf(fTable, "\n");
}


/**
 * @brief Compress a file using huffman coding
 *
 * @param inputFile name of the input file
 * @param outputFile name of the output file
 */
void compress(char inputFile[], char outputFile[]) {
    FILE* fin, * fout, * tmpFile;
    // Setting the charCode list
    Code c;
    c.val = '\0';
    strcpy(c.code, "");
    for (int i = 0; i < 256; i++) {
        charCodes[i] = c;
    }

    // Reading the file
    fin = fopen(inputFile, "r");
    if (fin == NULL) {
        printf("Unable to open the input file\n");
        exit(0);
    }

    // creating character array
    ele* empty = createElement('\0', 0);
    int arrIndex = 0;
    ele* arr[256];
    for (int i = 0; i < 256; i++) {
        arr[i] = empty;
    }

    // Getting the frequencies of each character
    while (feof(fin) == 0) {
        char a = '\0';
        fscanf(fin, "%c", &a);

        if (a == '\0')  continue;

        int i = find(arr, arrIndex, a);
        if (i != -1) {
            arr[i]->freq += 1;
        }
        else {
            arr[arrIndex] = createElement(a, 1);
            arrIndex += 1;
        }
    }


    // Huffman coding
    ele* codeStruct;
    codeStruct = huffman(arr, arrIndex);

    // Printing codes
    printCode(codeStruct, "");

    // closing the file
    fclose(fin);

    // Reading the file
    fin = fopen(inputFile, "r");
    if (fin == NULL) {
        printf("Unable to open the input file\n");
        exit(0);
    }


    // Writing to the file
    int bitsWritten = 0;

    tmpFile = tmpfile();

    // encoding
    bitsWritten = encode(fin, tmpFile);

    fclose(fin);

    // Writing the huffman table
    fout = fopen(outputFile, "w");
    tableWrite(fout, arr, bitsWritten);

    // Seeking to the top
    rewind(tmpFile);

    char val;
    while (feof(tmpFile) == 0) {
        fscanf(tmpFile, "%c", &val);
        fprintf(fout, "%c", val);
    }
}


/////////////////// Decompress the file ///////////////////
/**
 * @brief Reading the huffman metadata
 *
 * @param fTable pointer of the metadata file
 * @return binary tree of the codes created using metadata
 */
ele* readTable(FILE* fTable) {
    // creating character array
    ele* empty = createElement('\0', 0);
    int arrIndex = 0;
    ele* arr[256];
    for (int i = 0; i < 256; i++) {
        arr[i] = empty;
    }

    // Getting frequency of the file
    while (feof(fTable) == 0) {
        char a = '\0';
        int freq;
        fscanf(fTable, "%c", &a);

        // managing whitespaces
        if (a == ' ')           continue;
        else if (a == '\n')     break;
        else if (a == '\0')     continue;

        fscanf(fTable, "%d", &freq);

        arr[arrIndex] = createElement(a, freq);
        arrIndex += 1;
    }

    // Huffman coding
    ele* codeStruct;
    codeStruct = huffman(arr, arrIndex);

    return codeStruct;
}

/**
 * @brief Find the character from the code
 *
 * @param root Binary tree that contains the code
 * @param q queue that contains the code
 * @return decoded character
 */
char findChar(ele* root, char q[]) {
    char tmp;
    int val;

    if (root->right == NULL && root->left == NULL)
        return root->val;

    tmp = pop(q);

    if (tmp == '\0')
        return '\0';
    if (tmp == '0')
        val = findChar(root->left, q);
    else if (tmp == '1')
        val = findChar(root->right, q);

    if (val == '\0') {
        insertQ(q, tmp);
    }

    return val;

}


/**
 * @brief Decode all the characters
 *
 * @param fin input file pointer
 * @param fout output file pointer
 * @param codeStruct Binary tree of the codes
 * @param bitsWritten number of bits written while compressing the file
 */
void decode(FILE* fin, FILE* fout, ele* codeStruct, long int bitsWritten) {
    int a = 0;
    char val;
    char bin[9];
    char q[64];
    long int bitsRead = 0;

    while (feof(fin) == 0) {
        a = 0;
        fscanf(fin, "%c", &a);

        // Converting a to binary
        int bin[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
        char binary[9] = "";
        for (int i = 7; i >= 0 && a != 0; i--) {
            bin[i] = a % 2;
            a /= 2;
        }
        for (int i = 0; i < 8; i++) {
            strcat(binary, bin[i] ? "1" : "0");
        }

        // adding to the queue
        for (int i = 0; i < 8; i++) {
            bitsRead += 1;
            if (bitsRead > bitsWritten)     break;

            push(q, binary[i]);
        }

        // Finding the character
        while (1) {
            val = findChar(codeStruct, q);

            if (val == '\0')
                break;

            fprintf(fout, "%c", val);
        }
    }
}

/**
 * @brief Decompress the huffman file
 *
 * @param inputFile name of the input file
 * @param outputFile name of the output file
 */
void decompress(char inputFile[], char outputFile[]) {
    FILE* fin, * fout;
    long int bitsWritten;

    ele* codeStruct;

    // Reading the table to get the codes
    fin = fopen(inputFile, "r");

    // Reading the file
    fscanf(fin, "%ld", &bitsWritten);

    codeStruct = readTable(fin);

    // decoding the file
    fout = fopen(outputFile, "w");

    decode(fin, fout, codeStruct, bitsWritten);

    fclose(fin);
    fclose(fout);
}

/////////////////// Main Function ///////////////////
int main() {
    char inputFile[100] = "out.txt";
    char outputFile[100] = "res.txt";
    int mode = 1;

    printf("Enter the input file name: ");
    scanf("%s", inputFile);

    printf("Enter the name of the output file: ");
    scanf("%s", outputFile);

    printf("Enter the mode: Compression or Decompression (0/1): ");
    scanf("%d", &mode);

    // Compression mode
    if (mode == 0) {
        compress(inputFile, outputFile);
    }

    // Decompression mode
    else if (mode == 1) {
        decompress(inputFile, outputFile);
    }


    return 0;
}