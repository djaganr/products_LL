product
- id
- name
- price

functions:
- updated id
- delete id
- insert id
- list all products
- search based on name and print all that match
- save

----

-> to access the members of the struct that a pointer variable refers
pointer_variable -> variable = value;



item1.next = &item2;
    item2.next = &item3;
    item3.next = &item4;
    item4.next = &item5;
    item5.next = NULL;



malloc() is a function that makes a system call—it asks the operating system for some number of bytes of memory. If it succeeds, you get a pointer to your newly allocated memory; if it fails, you get a NULL pointer and errno is set to ENOMEM (out of memory).


http://www.cs.toronto.edu/~heap/270F02/node31.html