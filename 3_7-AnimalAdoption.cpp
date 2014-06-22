// implement animal adoption in animal shelter

#include <iostream>
#include <list>

using namespace std;

class Animal
{
public:
	Animal(string n)
	{
		name = n;
	}
	virtual string getname() = 0;
    
	void setOrder(int ord)
	{
		order = ord;
	}
	int getOrder()
	{
		return order;
	}
	bool isOlderThan(Animal &a)
	{
		return this->order < a.getOrder();
	}
protected:
    string name;
private:
	int order;
};

class Dog : public Animal
{
public:
    Dog(string n):Animal(n)
    {
    }
	string getname() {
		return "Dog: " + name;
    }
};

class Cat : public Animal
{
public:
    Cat(string n):Animal(n)
    {
    }
    string getname(){
        return "Cat: " + name;
    }
};

class AnimalQueue
{
public:
    void enqueue(Animal a)
    {
        /*order is used as a sort of timestamp, so that we can
         compare the insertion order of a dog to a cat.*/
        a.setOrder(order);
        order++;
        if(a.getname()[0] == 'D')
            dogs.push_back(const &a);
        else if(a.getname()[0] == 'C')
            cats.push_back(const &a);
    }
    Animal dequeueAny()
    {
        // look at tops of dogs and cats queues, and pop the oldest
        if(dogs.size() == 0)
            return dequeueCats();
        else if(cats.size() == 0)
            return dequeueDogs();
        Dog dog = dogs.front();
        Cat cat = cats.front();
        if(dog.isOlderThan(cat))
            return dequeueDogs();
        else
        {
            return dequeueCats();
        }
    }
    Dog dequeueDogs()
    {
        Dog dog = dogs.front();
        dogs.pop_front();
        return dog;
    }
    Cat dequeueCats()
    {
        Cat cat = cats.front();
        cats.pop_front();
        return cat;
    }
    int size() {
		return dogs.size() + cats.size();
	}
    
private:
    int order = 0;
    list<Dog> dogs;
    list<Cat> cats;
};

int main()
{
    AnimalQueue animals;
    animals.enqueue(Cat("Callie"));
    animals.enqueue(Cat("Kiki"));
    animals.enqueue(Dog("Fido"));
    animals.enqueue(Dog("Dora"));
    animals.enqueue(Cat("Kari"));
    animals.enqueue(Dog("Dexter"));
    animals.enqueue(Dog("Dobo"));
    animals.enqueue(Cat("Copa"));
    
    cout << animals.dequeueAny().getname() << endl;
    cout << animals.dequeueAny().getname() << endl;
    cout << animals.dequeueAny().getname() << endl;
    
    animals.enqueue(Dog("Dapa"));
    animals.enqueue(Cat("Kilo"));
    
    while(animals.size() != 0)
    {
        cout << animals.dequeueAny().getname() << endl;
    }
    return 0;
}

