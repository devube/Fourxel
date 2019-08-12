#pragma once

#include <cstdio>
#include <GPUdata/vertexBufferObject.hpp>
#include <GPUdata/elementBufferObject.hpp>

namespace renderer {
    /**
     * @brief Stores model data
     * 
     * Create model object by calling Model::Load()
     * ```
     * Model *cube = Model::Load("assets/cube.obj");
     * // ...
     * delete cube;
     * ```
     */
    class Model {
    private:
        /**
         * @brief Stores vertices data
         * 
         */
        GPUdata::VertexBufferObject *vertices;
<<<<<<< HEAD

        /**
         * @brief Stores indeces data
         * 
         */
        GPUdata::ElementBufferObject *indeces;
=======
        GPUdata::ElementBufferObject *indices;
>>>>>>> dbc54e254931a7dd75c7a0be0404921297e86a5e

    public:
        /**
         * @brief Loads model from file
         * ```
         * Model *cube = Model::Load("assets/cube.obj");
         * // ...
         * delete cube;
         * ```
         * 
         * @param path Path to file
         * @return Model* Loaded model
         */
        static Model *load(const char *path);
        /**
         * @brief Loads multiple models from filesystem
         * ```
         * size_t count = 3;
         * Model **models = Model::load_many((char **){
         *     "assets/cube.obj",
         *     "assets/piramid.obj",
         *     "assets/plane.obj",
         * }, count);
         * // ...
         * delete[] models;
         * ```
         * 
         * @param path Array of char* containing path to models
         * @param count Count of models to load
         * @return Model** Array of Model*
         */
        static Model **load_many(const char **path, size_t count);

        ~Model();
    };
}
