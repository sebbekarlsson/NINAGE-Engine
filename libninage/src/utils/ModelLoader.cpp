#include "../includes/utils/ModelLoader.h"


bool replace(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

std::map<std::string, Model3D*> ModelLoader::models;

/**
 * Load a 3D model
 *
 * @param std::string filepath
 *
 * @return Model3D
 */
Model3D* ModelLoader::load(std::string filepath) {
    if (ModelLoader::models.count(filepath))
        return ModelLoader::models.find(filepath)->second;
    
    Model3D* model = new Model3D();
    
    ResourceManager::load(filepath);
    std::string model_contents = ResourceManager::get(filepath);
    std::istringstream iss(model_contents);

    for (std::string line; std::getline(iss, line);) {
        if(line.find("v ") != std::string::npos) {
            // v
            std::istringstream wiss(line);
            std::string word;
            int c = 0;
            std::vector<float> vertices;
            while(wiss >> word) {
                if (c == 0) { c++; continue; }

                vertices.push_back(std::stof(word));
                c++;
            }
            model->vertices.push_back(vertices);
        }
        if(line.find("vn ") != std::string::npos) {
            // vn
            std::istringstream wiss(line);
            std::string word;
            int c = 0;
            std::vector<float> vertices;
            while(wiss >> word) {
                if (c == 0) { c++; continue; }

                vertices.push_back(std::stof(word));
                c++;
            }
            model->vertexNormals.push_back(vertices);
        }
        else if(line.find("vt ") != std::string::npos) {
            // vt
            std::istringstream wiss(line);
            std::string word;
            int c = 0;
            std::vector<float> vertices;
            while(wiss >> word) {
                if (c == 0) { c++; continue; }

                vertices.push_back(std::stof(word));
                c++;
            }
            model->texcoords.push_back(vertices);

        }
        // TODO: Implement later
        /*else if(line.find("vp ") != std::string::npos) {
            // vp
            std::istringstream wiss(line);
            std::string word;
            int c = 0;
            std::vector<float> vertices;
            while(wiss >> word) {
                if (c == 0) { c++; continue; }

                vertices.push_back(std::stof(word));
                c++;
            }
            model->vertexNormals.push_back(vertices);

        }*/
        else if(line.find("f ") != std::string::npos) {
            std::istringstream wiss(line);
            std::string word;
            int c = 0;
            std::vector<int> vertices;
            std::vector<int> vertexNormals;
            while(wiss >> word) {
                if (c == 0) { c++; continue; }

                if (word.find("//") != std::string::npos){
                    int vertexIndex = std::stoi(word.substr(0, word.find("//")));
                    std::string nIndexStr = word.substr(word.find("//") + std::string("//").size(), std::string::npos);
                    replace(nIndexStr, "\n", "");
                    int vertexNormalIndex =  std::stoi(nIndexStr);
                    
                    vertices.push_back(vertexIndex);
                    vertexNormals.push_back(vertexNormalIndex);
                } else {
                    vertices.push_back(std::stoi(word));
                }
                
                c++;
            }
            
            model->faces.push_back(vertices);
            model->vertexNormalsIndices.push_back(vertexNormals);
        }
    }


    ModelLoader::models.operator[](filepath) = model; // store model in the map

    return model;
}

/**
 * Clear the models vector cache
 *
 * @return void
 */
void ModelLoader::clearModelcache() {
    ModelLoader::models.clear();
}
