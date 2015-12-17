#include "common.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"
#include <vector>
#include <string>

namespace glimac {

class Model {

	public: 
		Model(GLchar* path);
		void Draw(Shader shader);

	private:
		vector<Mesh> meshes;
		string directory;

		void loadModel(string path);
		void processNode(aiNode* node, const aiScene* scene);
		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
		vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);

};

}