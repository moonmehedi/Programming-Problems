#include <bits/stdc++.h>
using namespace std;

class CWH
{
protected:
    string title;
    float rating;

public:
    CWH(string title, float rating)
    {
        this->title = title;
        this->rating = rating;
    }
    virtual void display()
    {
        cout << "display from CWH class " << endl;
        cout << "video title " << title << endl;
        cout << "rating " << rating << endl;
    }
};

class CWHvideo : public CWH
{

    int videolength;

public:
    CWHvideo(int len, string title, int rating) : CWH(title, rating)
    {
        videolength = len;
    }
    void display()
    {
        cout << "this is display fun of video len class " << endl;
        cout << "this is an amazing video with title " << title << endl;
        cout << "rating " << rating << endl;
        cout << "video length " << videolength << endl;
    }
};

class CWHtext : public CWH
{
    int wordcount;

public:
    CWHtext(int wordcount, string title, int rating) : CWH(title, rating)
    {
        this->wordcount = wordcount;
    }
    void display()
    {
        cout << "display funtion of text class " << endl;
        cout << "this is an amazing video with title " << title << endl;
        cout << "rating " << rating << endl;
        cout << "word count " << wordcount << endl;
    }
};
int main()
{
    // creating ob of base class
    CWHvideo ob_video(20, "notitle", 4.5);
    CWHtext ob_text(200, "one title", 5.5);

    ob_video.display();
    ob_text.display();

    CWH *arr[2];
    arr[0] = &ob_video;
    arr[1] = &ob_text;


    //as we have write virtual before display function it will be bined
    arr[0]->display();
    arr[1]->display();
}