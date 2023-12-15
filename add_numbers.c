//
// Created by rajan on 13/12/23.
//
#include <Python.h>

// The C function we want to expose to Python
static PyObject* add_numbers_impl(PyObject* self, PyObject* args){
    //using 'self' and thus preventing the warning
    (void)self;
    int x;
    int y;
    if (!PyArg_ParseTuple(args,"ii", &x, &y)){
        return NULL;
    }
    return Py_BuildValue("i", x + y);
}

// Struct for defining module methods
static PyMethodDef module_methods[] = {
        {"add_numbers_impl", add_numbers_impl, METH_VARARGS, NULL},
        {NULL,NULL,0,NULL}
};

// Module definition
static struct PyModuleDef add_numbers_module = {
        PyModuleDef_HEAD_INIT,
        "add_numbers",
        NULL,
        -1,
        module_methods,
        NULL, // newly added fields
        NULL,
        NULL,
        NULL
};

// Module initialization
PyMODINIT_FUNC PyInit_add_numbers(void) {
    return PyModule_Create(&add_numbers_module);
}

