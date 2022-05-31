## Everything else




### below example shows that we can have properties like in C# if we use visual studio feature for language extentions.

```

class Person
{
public:
	Person();
	~Person();

public:
	__declspec(property(get = getAge, put = setAge)) int Age;

	int getAge() const { return Age; }
	void setAge(int age) { Age = age; }
};
```