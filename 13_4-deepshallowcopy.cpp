// show me the difference between a deep copy and a shallow copy

struct Test{
	char * ptr;
};

void shallow_copy(Test & src, Test & dest){
	dest.ptr = src.ptr;
}

void deep_copy(Test & src, Test & dest){
	dest.ptr = malloc(strlen(src.ptr) + 1);
	memcpy(dest.ptr, src.ptr);
}


shallow copy may cause a lot of programming errors, especially with the creation and deletion of objects
in most cases, deep copy is used. 
strlen is a c string method
Here is an example for strlen and memcpy

#include <iostream>
#include <cstring>
using namespace std;


struct {
  char name[40];
  int age;
} person, person_copy;

int main ()
{
  char myname[] = "Pierre de Fermat";

  /* using memcpy to copy string: */
  memcpy ( person.name, myname, strlen(myname)+1 );
  person.age = 46;

  /* using memcpy to copy structure: */
  memcpy ( &person_copy, &person, sizeof(person) );

  cout << person_copy.name << ' ' << person_copy.age;

  return 0;
}
