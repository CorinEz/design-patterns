using System;

interface IInternal
{
    string Fetch();
}

class InternalClass : IInternal
{
    public string Fetch()
    {
        return "get user info";
    }
}

class ExternalClass
{
    public string Search()
    {
        return "get user info";
    }
}

class Adapter : IInternal
{
    private ExternalClass _external;

    public Adapter(ExternalClass external)
    {
        _external = external;
    }

    public string Fetch()
    {
        return _external.Search();
    }
}

class Program
{
    static void Main()
    {
        IInternal internalClass = new InternalClass();
        Console.WriteLine(internalClass.Fetch()); // get user info

        ExternalClass external = new ExternalClass();
        IInternal adapter = new Adapter(external);
        Console.WriteLine(adapter.Fetch()); // get user info
    }
}
