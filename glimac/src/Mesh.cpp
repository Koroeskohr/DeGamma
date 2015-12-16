//
// Created by koro on 15/12/15.
//

#include "Mesh.hpp"

namespace glimac {
    Mesh::Mesh (const aiMesh *mesh, const std::string& materialName)
        : mMaterialName(materialName)
    {
        /*
         * TODO : get aiMesh from scene in Model class
         * /
    }

}

