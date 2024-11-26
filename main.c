#include <iostream>
#include <string>
#include <cstdio>
#include <stdexcept>

using namespace std;

// Estructura para la coloración de consola (en este caso, solo un ejemplo)
struct ColorConsole {
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
    static constexpr auto reset = "\033[0m";
};

// Simulación de ConsoleBox
struct ConsoleBox {
    void new_text() { /* Simulación de creación de nuevo texto */ }
    void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox; // Inicialización

// Función para cargar y procesar scripts
void load_script(const char *filename, bool show_script = false) {
    if (!filename) {
        cerr << "Error: Nombre de archivo no proporcionado." << endl;
        return;
    }

    FILE *file = fopen(filename, "rb");
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo '" << filename << "'." << endl;
        return;
    }

    string script;
    char buffer[4096];
    size_t bytesRead;

    try {
        while ((bytesRead = fread(buffer, 1, sizeof(buffer) - 1, file)) > 0) {
            buffer[bytesRead] = '\0'; // Asegura el término nulo
            script.append(buffer);
        }

        if (ferror(file)) {
            throw runtime_error("Error al leer el archivo.");
        }

        fclose(file);
        file = nullptr;

        if (show_script) {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white
                 << script << ColorConsole::reset << endl;
        }

        consoleBox->new_text();
        consoleBox->set_text(script);
    } catch (const exception &e) {
        cerr << "Excepción: " << e.what() << endl;
        if (file) fclose(file);
    } catch (...) {
        cerr << "Error desconocido durante la lectura del archivo." << endl;
        if (file) fclose(file);
    }
}

// Función para solicitar el archivo al usuario
void load_script() {
    string filename;
    cout << "Ingrese el nombre del archivo: ";
    getline(cin, filename);

    if (filename.empty()) {
        cerr << "Error: No se ingresó un nombre de archivo." << endl;
        return;
    }

    load_script(filename.c_str(), true);
}

int main() {
    try {
        load_script(); // Llama a la versión interactiva
    } catch (const exception &e) {
        cerr << "Error inesperado: " << e.what() << endl;
    }

    return 0;
}
