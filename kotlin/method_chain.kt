class Calculator {
    private var result: Double = 0.0

    fun add(value: Double): Calculator {
        result += value
        return this
    }

    fun subtract(value: Double): Calculator {
        result -= value
        return this
    }

    fun multiply(value: Double): Calculator {
        result *= value
        return this
    }

    fun divide(value: Double): Calculator {
        if (value != 0.0) {
            result /= value
        }
        return this
    }

    fun getResult(): Double {
        return result
    }
}

fun main() {
    val calc = Calculator()
    val result = calc.add(5.0)
                     .multiply(2.0)
                     .subtract(3.0)
                     .divide(2.0)
                     .getResult()
    println(result) // 출력: 3.5
}
