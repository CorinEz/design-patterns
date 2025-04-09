interface Coffee {
    fun cost(): Int
}

class SimpleCoffee : Coffee {
    override fun cost(): Int = 5
}

open class CoffeeDecorator(private val coffee: Coffee) : Coffee {
    override fun cost(): Int = coffee.cost()
}

class MilkDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int = super.cost() + 2
}

class SugarDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int = super.cost() + 1
}

fun main() {
    val coffee: Coffee = SimpleCoffee()
    println(coffee.cost()) // 5

    val coffeeWithMilk: Coffee = MilkDecorator(coffee)
    println(coffeeWithMilk.cost()) // 7

    val coffeeWithSugar: Coffee = SugarDecorator(coffee)
    println(coffeeWithSugar.cost()) // 6

    val coffeeWithMilkAndSugar: Coffee = SugarDecorator(coffeeWithMilk)
    println(coffeeWithMilkAndSugar.cost()) // 8
}
