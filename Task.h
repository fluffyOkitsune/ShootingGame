#pragma once

class Task {
public : 
    virtual ~Task(){}

	//‰Šú‰»
    virtual void Initialize(){}

	//I—¹
    virtual void Finalize(){}

	//XV
    virtual void Update() = 0;

	//•`‰æ
    virtual void Draw() = 0;
};
