#include<iostream>
using namespace std;

int main(int argc , char* argv[])
{
	cout<<"Number of arguments:"<<argc<<endl;
	for(int i=0;i<argc;i++)
	{
		cout<<"Argument is :"<<i<<":"<<argv[i]<<endl;
		int a = stoi(argv[3]);
		cout<<"A is :"<<a<<endl;
	}

	return 0;
}

/*
 * A segsegv means that program tried to access memory it wasn't allowed to -
 * using gdb-> gbd ./a.out 1 2 3 4
 * run 1 2 3 4 
 * bt (backtrace)
 * break <linenumber>
 * run <cli>
 * continue after each break point>
 *
 * using valgrind for debug 
 * valgrind ./a.out 1 2 3 4
 * --leak-check=full
 * */
/*
 * ==2792== Memcheck, a memory error detector
==2792== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2792== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==2792== Command: ./a.out 1 2 3
==2792==
Number of arguments:4
Argument is :0./a.out
A is :3
Argument is :11
A is :3
Argument is :22
A is :3
Argument is :33
A is :3
==2792==
==2792== HEAP SUMMARY:
==2792==     in use at exit: 0 bytes in 0 blocks
==2792==   total heap usage: 2 allocs, 2 frees, 73,728 bytes allocated
==2792==
==2792== All heap blocks were freed -- no leaks are possible
==2792==
==2792== For lists of detected and suppressed errors, rerun with: -s
==2792== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/
