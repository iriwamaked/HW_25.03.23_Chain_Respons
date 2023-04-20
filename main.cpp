#include <iostream>
#include <string>
using namespace std;
class Translator {
protected:
    Translator* next;
    string language;
public:
    Translator(const string& language) : next(nullptr), language(language) {}
    void setNext(Translator* next) {
        this->next = next;
    }
    virtual string translate(const string& message, const string& toLanguage) = 0;
};

class EnglishTranslator : public Translator {
public:
    EnglishTranslator() : Translator("english") {}
    string translate(const string& message, const string& toLanguage) override {
        if (toLanguage == language) {
            return message;
        }
        else if (next != nullptr) {
            return next->translate(message, toLanguage);
        }
        else {
            return "Translation not available";
        }
    }
};

class FrenchTranslator : public Translator {
public:
    FrenchTranslator() : Translator("french") {}
    string translate(const string& message, const string& toLanguage) override {
        if (toLanguage == language) {
            return message;
        }
        else if (next != nullptr) {
            return next->translate(message, toLanguage);
        }
        else {
            return "Translation not available";
        }
    }
};

class GermanTranslator : public Translator {
public:
    GermanTranslator() : Translator("german") {}
    string translate(const string& message, const string& toLanguage) override {
        if (toLanguage == language) {
            return message;
        }
        else if (next != nullptr) {
            return next->translate(message, toLanguage);
        }
        else {
            return "Translation not available";
        }
    }
};

int main() {
    EnglishTranslator englishTranslator;
    FrenchTranslator frenchTranslator;
    GermanTranslator germanTranslator;

    englishTranslator.setNext(&frenchTranslator);
    frenchTranslator.setNext(&germanTranslator);

    string message = "Hello, world!";
    string translatedMessage = englishTranslator.translate(message, "italian");

    cout << "Original message: " << message << std::endl;
    cout << "Translated message: " << translatedMessage << std::endl;

    return 0;
}
