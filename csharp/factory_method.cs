using System;

abstract class Animal
{
    public abstract string Speak();
}

class Dog : Animal
{
    public override string Speak()
    {
        return "Woof!";
    }
}

class Cat : Animal
{
    public override string Speak()
    {
        return "Meow!";
    }
}

class AnimalFactory
{
    public static Animal CreateAnimal(string animalType)
    {
        if (animalType == "dog")
            return new Dog();
        else if (animalType == "cat")
            return new Cat();
        else
            return null;
    }
}

class Program
{
    static void Main()
    {
        Animal dog = AnimalFactory.CreateAnimal("dog");
        if (dog != null) Console.WriteLine(dog.Speak()); // Woof!

        Animal cat = AnimalFactory.CreateAnimal("cat");
        if (cat != null) Console.WriteLine(cat.Speak()); // Meow!
    }
}
