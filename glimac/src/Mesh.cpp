//
// Created by koro on 15/12/15.
//

#include "Mesh.hpp"

namespace glimac {
    Mesh::Mesh (std::vector<Vertex>& vertices, std::vector<unsigned>& indices, const std::string& materialName)
        : mVertices(vertices),
          mIndices(indices),
          mMaterialName(materialName)
    {
    }

        /*
         * TODO : get aiMesh from scene in Model class
         * /
    }

}

