#include <iostream>
#include <string>
using namespace std;
#include <windows.h> 

class Fonts{     
    
    protected:
        int _size;
        string _color="Green";
        Fonts(int size, string color):_size(size),_color(color){};
    
    public:
        int getSize(){
            return _size;
        };
        
        string getColor(){
            return _color;
        };
        //lets the subclass decide how to implement this
        virtual string getDetails()=0;
};

class GreenFonts:public Fonts{
    int _greenVal=0;  
    public:
        GreenFonts(int size, int greenVal):Fonts(size,"Green"){
            _greenVal=greenVal;
        };

        int getGreenVal(){
            return _greenVal;
        }

        string getDetails(){
            return "Green Text with test size "+to_string(_size)+" green value of "+to_string(_greenVal);
        }

};

class BlackFonts:public Fonts{
    public:
        BlackFonts(int size):Fonts(size,"Black"){};
        string getDetails(){
            return "Black Text with test size "+to_string(_size);
        }

};

class WhiteFonts:public Fonts{
    public:
        WhiteFonts(int size):Fonts(size,"Black"){};
        string getDetails(){
            return "WHite Text with test size "+to_string(_size);
        }
    
};


class Background{
    string _theme=NULL;
    protected:
        Background(string theme):_theme(theme){};
    public:
        virtual string getTheme()=0;

};

class WhiteBackground:public Background{
    public:
        WhiteBackground():Background("white"){};
        string getTheme(){
            return "This is a white Background";
        }
};

class DarkBackground:public Background{
    public:
        DarkBackground():Background("Dark"){};
        string getTheme(){
            return "This is a dark Background";
        }


};

class ThemeFactory{
    protected:
        ThemeFactory(){};

    public:
        virtual Background * getBackground()=0;
        virtual Fonts * getFont()=0;
        virtual Fonts * getGreenFont()=0;
};

class DarkThemeFactory: public ThemeFactory{
    int whiteFontSize=8;
    int greenFontSize=9;
    int greenFontsIntensity=10;
    public:
        DarkThemeFactory(){};
        Background * getBackground(){
            return new DarkBackground();
        };

        Fonts * getFont(){
            return new WhiteFonts(whiteFontSize);
        };

        Fonts * getGreenFont(){
            return new GreenFonts(greenFontSize,greenFontsIntensity );
        }

};

class LightThemeFactory:public ThemeFactory{
    int darkFontSize=8;
    int greenFontSize=10;
    int greenFontsIntensity=20;
    public:
        LightThemeFactory(){};
        Background * getBackground(){
            return new WhiteBackground();
        };

        Fonts * getFont(){
            return new WhiteFonts(darkFontSize);
        };

        Fonts * getGreenFont(){
            return new GreenFonts(greenFontSize,greenFontsIntensity );
        }

};

//client only knows of ThemeFactory and Fonts classes. 
void client(ThemeFactory * factory){
    cout<<"Client received the Factory"<<endl;
    Background* bg=factory->getBackground();
    cout<<"Theme "<<bg->getTheme()<<endl;

    Fonts* font=factory->getFont();
    cout<<"Font "<< font->getDetails()<<endl;

    Fonts* gFont = factory->getGreenFont();
    cout<<"Font green "<< gFont->getDetails()<<endl;


    delete bg;
    delete font;
    delete gFont;

    cout<<endl;

}

int main(){
    ThemeFactory * factory1=new DarkThemeFactory();
    client(factory1);
    delete factory1;

    ThemeFactory * factory2=new LightThemeFactory();
    client(factory2);
    delete factory2;

}