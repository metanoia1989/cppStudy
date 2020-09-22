#include <iostream>
#include "stock00.h"

int main()
{
    {
        using std::cout;
        cout << "Using constructors to create new objects\n";
        Stock fluffy_the_cat("NanoSmart", 20, 12.50);
        fluffy_the_cat.show();
        Stock fluffy_the_dog("Boffo Objects", 2, 2.0);
        fluffy_the_dog.show();

        cout << "Assigning fluffy_the_cat to fluffy_the_dog:\n";
        fluffy_the_dog = fluffy_the_cat;
        cout << "Listing fluffy_the_cat and fluffy_the_dog:\n";
        fluffy_the_cat.show();
        fluffy_the_dog.show();

        cout << "Using a constructor to reset an object\n";
        fluffy_the_cat = Stock("Nifty Foods", 10, 50.0);
        cout << "Revised fluffy_the_cat:\n";
        fluffy_the_cat.show();
        cout << "Done\n";
    }

    return 0;
}
