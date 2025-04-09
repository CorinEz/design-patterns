interface Internal {
    fun fetch(): String
}

class InternalClass : Internal {
    override fun fetch(): String {
        return "get user info"
    }
}

class ExternalClass {
    fun search(): String {
        return "get user info"
    }
}

class Adapter(private val external: ExternalClass) : Internal {
    override fun fetch(): String {
        return external.search()
    }
}

fun main() {
    val internal: Internal = InternalClass()
    println(internal.fetch()) // get user info

    val external = ExternalClass()
    val adapter: Internal = Adapter(external)
    println(adapter.fetch()) // get user info
}
