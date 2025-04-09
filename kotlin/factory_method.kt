abstract class Animal {
    abstract fun speak(): String
}

class Dog : Animal() {
    override fun speak(): String {
        return "Woof!"
    }
}

class Cat : Animal() {
    override fun speak(): String {
        return "Meow!"
    }
}

object AnimalFactory {
    fun createAnimal(animalType: String): Animal? {
        return when (animalType) {
            "dog" -> Dog()
            "cat" -> Cat()
            else -> null
        }
    }
}

fun main() {
    val dog = AnimalFactory.createAnimal("dog")
    println(dog?.speak()) // Woof!

    val cat = AnimalFactory.createAnimal("cat")
    println(cat?.speak()) // Meow!
}
