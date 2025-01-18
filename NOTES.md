## Vector access
access vectors like this: ```Name[i]```

## Get length of vector
name.size(); //returns the size of a list

## Access charicters in a string
name[i];

## Get string substring
name.substr(index, length)// inclusive
//length starts at self, ie, index, 1 = capture self, 0 = nothing

## Find string in string
int index = name.find("what to find")
if (index != std::string::npos) {
    return false;
}
else {
    index is the index of the start of string
}

## Delete index for sting (and others)
```
string.erase(string.begin() + index) // erases the index in that string
string.erase(string.begin() + index, sting.begin() + endindex) // erases range of strings, peram 2 is exclusive

```

## Listnode - slightly linked list
