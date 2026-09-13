/*
 * Course: COEN 2220 - Programming 2
 * Name: [Sebastian N. Ortiz Mercado]
 * Lab: Lab 4 - Object-Oriented Programming, Part 2
 * Description: Aggregation practice with CourseSection
 * Due date: [9/13/2026]
 */
#include <iostream>
using namespace std;

class StudyTime
{
    private:
        int minutes;               // Each object stores its own duration.
        static int objectCount;    // One counter is shared by the entire class.

    public:
        StudyTime(int m = 0) {
            minutes = m;
            objectCount++;         // Every new object increases the shared count.
        }

        int getMinutes() const { return minutes; }

        static int getObjectCount() {
            return objectCount;    // A static function reads class-level data.
        }

        // --- STEP 2: copy constructor (uncomment the /* ... */ block later) ---
        
        StudyTime(const StudyTime &other) {
            minutes = other.minutes;  // Copy the source object's duration.
            objectCount++;            // The copy is a new object too.
        }
        

        // --- STEP 3: operator+ (uncomment the /* ... */ block later) ---
        
        StudyTime operator+(const StudyTime &other) const {
            // Return a new duration without changing either operand.
            return StudyTime(minutes + other.minutes);
        }
        bool operator==(const StudyTime &other) const {
            // Return true if both objects represent the same duration.
            return minutes == other.minutes;
        }
        
};

int StudyTime::objectCount = 0;    // Define the single shared variable.

int main() {

    StudyTime reading(45); // The first StudyTime object.
    
    cout << "Reading: " << reading.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;

    // --- STEP 2 main() code goes here later ---
    StudyTime readingCopy = reading;  // Create a new object from reading.
    cout << "Copy: " << readingCopy.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;
    // --- STEP 3 main() code goes here later ---
    StudyTime practice(30);
    StudyTime total = reading + practice;  // Calls reading.operator+(practice).

    cout << "Total: " << total.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;

    // ===== Resuelve estos TODO ahora (Parte E) =====

        // TODO (Parte E): Define operator== so two StudyTime objects are equal
        // when they represent the same number of minutes. The function must not
        // modify either object and must return a bool.
    StudyTime Math(60);
    StudyTime MathCopy;
    MathCopy = Math;  // This assigns Math to MathCopy.

    StudyTime Science(30);

        bool areEqual = (Math == MathCopy);  // Calls Math.operator==(MathCopy).
        cout << "Are Math and MathCopy equal? " << (areEqual ? "Yes" : "No") << endl;

        bool Equal = (Math == Science);  // Calls Math.operator==(Science).
        cout << "Are Math and Science equal? " << (Equal ? "Yes" : "No") << endl;

    //parte D
    //Crea un objeto nuevo inicializado desde reading.

    StudyTime otherCopy = reading; 

    //Crea otro objeto nuevo con la duración por default.

    StudyTime deafault;
    //Asigna reading sobre el segundo objeto ya existente.

    deafault=reading;

    //Imprime el valor final de StudyTime::getObjectCount() y los minutos de ambos objetos.

    cout << "OtherCopy: " << otherCopy.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;

    cout << "Default: " << deafault.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;
    return 0;
}