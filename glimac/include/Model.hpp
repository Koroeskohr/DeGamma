#include "common.hpp"
#include <iostream>
#include "Shader.hpp"
#include "Mesh.hpp"
#include <vector>
#include <string>

#include "Image.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


namespace glimac {

GLint TextureFromFile(const char* path, string directory);

class Model {

	public: 
		Model(string path);
		void Draw(Program & program);

	private:
		vector<Mesh> meshes;
		string directory;

		void loadModel(string path);
		void processNode(aiNode* node, const aiScene* scene);
		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
		vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);

};



}