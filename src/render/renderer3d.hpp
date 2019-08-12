#pragma once

#include <render/model.hpp>
#include <render/renderer.hpp>

namespace Fourxel {
    namespace Graphics {
        class Renderer3d : public Renderer {
        private:

        public:
            /**
             * @brief Draws model on screen
             * 
             * @param model Model to render
             * @param world_transform Transformation that will be applayed first
             * @param model_transform Transformation that will be applayer after
             * @param model_position Position of model
             */
            void render_model(renderer::Model *model, float* world_transform, float* model_transform, float* model_position);
        };
    }
}