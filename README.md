# 🛠️ CMake Project: Adding and Building New Modules

This guide explains how to add a new subdirectory (module) to your CMake-based C++ project and compile it with minimal effort. It also shows how to compile only the specific module instead of rebuilding the whole project.

---

## Step 1: Create a New Module Directory

Create a new folder for your module under the root of your project. Inside it, create the C++ source files:

```bash
mkdir <module_name>
cd <module_name>
touch main1.cpp main2.cpp
```

Replace `<module_name>` with a descriptive name, such as `feature_detector`, `lab3`, etc.

---

## Step 2: Add a `CMakeLists.txt` in the New Module Directory

Inside the `<module_name>` directory, create a `CMakeLists.txt` file that looks like this:

```cmake
# <module_name>/CMakeLists.txt

add_executable(exec1 main1.cpp)
add_executable(exec2 main2.cpp)

target_link_libraries(exec1 ${OpenCV_LIBS})
target_link_libraries(exec2 ${OpenCV_LIBS})

add_custom_target(<module_name>
  DEPENDS exec1 exec2
)
```

- Replace `exec1`, `exec2` with the actual names of your executables.
- Replace `${OpenCV_LIBS}` with the required libraries your project uses.
- Ensure `<module_name>_all` matches your folder name for clarity.

---

## Step 3: Include the Module in the Root `CMakeLists.txt`

In your project’s root `CMakeLists.txt` file, add the following line to include your new module:

```cmake
add_subdirectory(<module_name>)
```

This tells CMake to look into that directory during configuration and build.

---

## Step 4: Configure the Project (Only Once or When Changes Are Made)

Go to the project root and configure the build using CMake:

```bash
mkdir -p build
cd build
cmake ..
```

This generates the required Makefiles. Only rerun this step if you change the CMake configuration (e.g., add a new subdirectory or update dependencies).

---

## Step 5: Build Only the New Module

Instead of building the whole project, you can build only the new module using:

```bash
make <module_name>
```

This builds only the executables defined in your module. It uses the custom target defined earlier in that module’s `CMakeLists.txt`.

---

## Step 6: Run the Executables

After the build completes, run your executables from the build directory:

```bash
./exec1
./exec2
```

Or navigate to their exact location depending on how your CMake output is structured.

---

## Summary Table

| Step | Action |
|------|--------|
| 1 | Create new directory and `.cpp` files |
| 2 | Add a module-level `CMakeLists.txt` with `add_executable` and `add_custom_target` |
| 3 | Add `add_subdirectory(<module_name>)` in root `CMakeLists.txt` |
| 4 | Run `cmake ..` from inside the `build` directory |
| 5 | Run `make <module_name>_all` to compile only the new module |
| 6 | Run the compiled binaries |

---

## Tips

- You can copy an existing module (e.g., `lab2`) and rename files and executables to create a new one quickly.
- Always ensure custom targets (`<module_name>_all`) are uniquely named per module.
- Avoid rebuilding the entire project by building modules selectively.
