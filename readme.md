# get_next_line()

```C
char	*get_next_line(int fd);
```

## what does it do ?
`get_next_line` allows us to read a file line by line from a file descriptor.

## return value
`get_next_line` returns the next line, or (null) in case of bad file descriptor, end-of-file or malloc failure.

Note that my function doesn't properly handle the reading from multiple file descriptors during the same program execution except if the first file descriptor has been read until end with `get_next_line`.

## how does it work ?
`get_next_line` applies the following algorithm:

1. Initialize our line structure to (null)

2. While end-of-file has not been reached:

   1. If there are characters to look at in our static buffer:
		1. Prepare line for the append of these characters
		2. Append those characters to our line.
   2. Refill our static buffer with a call to `read`.

3. If end-of-file has been reached: 
	1. mark the buffer as reset.

6. Return the line string generated.

### why do we need a static variable ?
Calling the <unistd.h> `read` multiple times 1 byte at a time isn't very efficient. For this reason, we want to use a large buffer size, that we can modify for different uses by overwriting the macro BUFFER_SIZE.

But if the BUFFER_SIZE is 1024 for example, and the length of a line is 15, we have read to much characters and we need to save those in case we need to return the next line next time `get_next_line` is called.

### how do I handle dynamic memory allocation for the line ?
We do not know in advance what the size of the line will be.
So I cannot in advance allocate enough memory for my line.
Therefore, we must first allocate an initial amount of memory, then reallocate during the program.
I do this in powers of two:
The first time, I allocate 32 bytes. As soon as we have written 32 bytes and we need more space, I reallocate my string for it to have twice its capacity, thus, 64. Then we do the same, until we reach 64 bytes and reallocate 128 bytes. Then 256, 512, 1024 etc.
The reason I do this is because calls to malloc and free are expensive and fragment the memory and we'd rather not have to much of them. However, we cannot know in advance how big the line will be. Allocating exponentaly more allows us to adapt to very different line sizes.
`std:vector` in C++ works in a similar way.
A better explanation can be found here: [Stackoverflow - Is it better to allocate memory in powers of 2?](https://stackoverflow.com/questions/3190146/is-it-better-to-allocate-memory-in-the-power-of-two)
The advantage is also that knowing the index of where we're going to append the next character, we can compute the capacity of our line. Just round it up to the next power of 2.