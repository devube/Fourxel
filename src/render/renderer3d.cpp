#include "renderer3d.hpp"

using namespace Fourxel::Graphics;

void Renderer3d::render_model(
    renderer::Model *model,
    float* world_transform,
    float* model_transform,
    float* model_position) {

    

    glDrawArrays(GL_TRIANGLES, model->get_indieces(), model->get_indieces_size());
}