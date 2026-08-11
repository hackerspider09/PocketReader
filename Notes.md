Const args how they work: 

| Parameter Syntax | Creates a Copy? | Can Modify Original Object? | What Methods Can You Call? |
|---|---|---|---|
| User obj (Pass by Value) | Yes (Heavy memory usage) | No (Only modifies the temporary copy) | Any method (mutating or non-mutating) |
| const User& obj (Pass by Const Ref) | No (Lightweight/Efficient) | No (Compiler blocks changes) | Only const methods |
| User& obj (Pass by Non-Const Ref) | No (Lightweight/Efficient) | Yes (Directly changes the original) | Any method (mutating or non-mutating) |

## Code Example

void modifyUser(User& obj) {
    // 1. You can call non-const methods that change data
    obj.setName("New Name"); 
    
    // 2. You can call const methods that just read data
    std::cout << obj.getName(); 
}
int main() {
    User realUser;
    realUser.setName("Alice");

    modifyUser(realUser); 
    // realUser's name is now "New Name" in main() because no copy was made!
}

In modern C++, passing by const User& is the default choice for performance when you only want to read data. You switch to User& specifically when the function's purpose is to modify or update the original object.
thats why in bookreader we used Book& and const but here it needs const method which gurantees it not gonna change that object therfore it calls only const method
