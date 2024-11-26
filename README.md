# Proyecto: Carga de Scripts en Tiny-Lisp

## Descripción
Este proyecto implementa funciones en C++ para cargar scripts desde un archivo, mostrar su contenido con coloración sintáctica en la consola y manejar diversos errores que puedan ocurrir durante el proceso. Está diseñado para ejecutarse en el entorno **CLion** utilizando funciones estándar de C/C++ para garantizar portabilidad.

## Funciones principales
### 1. `load_script(const char* filename, bool show_script = false)`
Carga un archivo de texto dado su nombre y lo procesa. Puede mostrar el contenido en la consola con coloración sintáctica si `show_script` es `true`.

#### Parámetros
- `filename`: Nombre del archivo a cargar.
- `show_script`: Indica si se debe mostrar el contenido del archivo. Por defecto, es `false`.

#### Características
- Abre el archivo en modo binario.
- Lee su contenido en fragmentos utilizando un búfer.
- Si `show_script` es `true`, imprime el contenido con colores.
- Envía el contenido del archivo a un objeto `ConsoleBox` para ser procesado.

#### Manejo de errores
- Verifica si el archivo existe y puede ser abierto.
- Detecta errores de lectura utilizando `ferror`.
- Usa excepciones para capturar errores inesperados y asegurar que los recursos sean liberados correctamente.

---

### 2. `load_script()`
Solicita al usuario el nombre de un archivo, lo valida y llama a `load_script(const char* filename, bool show_script = false)`.

#### Funcionamiento
1. Solicita al usuario ingresar el nombre del archivo.
2. Valida que el nombre no esté vacío.
3. Llama a `load_script` con el nombre proporcionado y `show_script = true`.

---

### 3. `main()`
Es el punto de entrada del programa, que llama a la función interactiva `load_script()` y maneja errores globales si ocurren.

---

## Estructuras auxiliares
### `ColorConsole`
Define colores para la salida en la consola utilizando códigos ANSI:
- `fg_blue`: Color de texto azul.
- `bg_white`: Fondo blanco.
- `reset`: Restablece los colores de la consola al estado normal.

---

### `ConsoleBox`
Simula un componente de interfaz gráfica encargado de manejar y mostrar texto. Incluye dos métodos:
- `new_text()`: Simula la creación de un nuevo texto.
- `set_text(const string &text)`: Imprime el texto proporcionado en la consola.

---

## Manejo de errores
El código maneja múltiples casos de error de forma robusta:
1. **Archivo inexistente:** Muestra un mensaje indicando que el archivo no existe.
2. **Error al abrir el archivo:** Se asegura de que los recursos se liberen correctamente.
3. **Errores de lectura:** Detecta problemas durante la lectura del archivo utilizando `ferror`.
4. **Entradas inválidas:** Verifica que el usuario no ingrese un nombre de archivo vacío.

---

## Instrucciones de ejecución
1. Compila el código en CLion o cualquier entorno compatible con C++.
2. Ejecuta el programa. Aparecerá un mensaje solicitando el nombre del archivo:
Ingrese el nombre del archivo:

yaml
Copiar código
3. Ingresa el nombre del archivo que deseas cargar. Si el archivo existe, se mostrará su contenido en la consola con coloración.

---

## Ejemplo de salida
### Archivo existente
Si el archivo `script.lsp` contiene:
(defvar x 10) (print x)

Copiar código

Y lo cargas, el programa mostrará:
Ingrese el nombre del archivo: script.lsp <salida en azul con fondo blanco> (defvar x 10) (print x)

perl
Copiar código

### Archivo inexistente
Si intentas cargar un archivo que no existe:
Ingrese el nombre del archivo: archivo_inexistente.lsp Error: No se pudo abrir el archivo 'archivo_inexistente.lsp'.

csharp
Copiar código

---

## Estructura del código
```cpp
struct ColorConsole { ... };       // Manejo de colores en consola
struct ConsoleBox { ... };         // Simula la gestión de texto

void load_script(const char*, bool); // Carga scripts desde archivos
void load_script();                  // Versión interactiva

int main();                          // Punto de entrada
Rúbrica de evaluación
Carga de scripts (50 puntos)
Implementación de load_script(const char* filename, bool show_script = false): 25 puntos.
Implementación de load_script() interactiva: 25 puntos.
Manejo de errores (50 puntos)
Manejo de archivos inexistentes: 15 puntos.
Manejo de errores al abrir archivos: 15 puntos.
Manejo de errores de lectura: 20 puntos.
Puntuación total: 100 puntos.

Notas importantes
El programa utiliza funciones estándar de C/C++ (fopen, fread, etc.), en lugar de las funciones específicas de Microsoft (fopen_s), para garantizar compatibilidad multiplataforma.
Los colores en consola funcionan únicamente en terminales compatibles con códigos ANSI.
Puedes extender las funcionalidades de ConsoleBox para integrarlo con una interfaz gráfica real.
Autor
Encina, 2024.
