#include "../includes/utils/ModelLoader.h"


std::map<std::string, Model3D*> ModelLoader::models;

/**
 * Load a 3D model
 *
 * @param std::string filepath
 *
 * @return Model3D
 */
Model3D* ModelLoader::load(std::string filepath) {
    /* 
     * # List of geometric vertices, with (x,y,z[,w]) coordinates, w is optional and defaults to 1.0.
     *   
     * v 0.123 0.234 0.345 1.0
     * v ...
     *  ...
     * # List of texture coordinates, in (u, v [,w]) coordinates, these will vary between 0 and 1, w is optional and defaults to 0.
     * vt 0.500 1 [0]
     * vt ...
     * ...
     * # List of vertex normals in (x,y,z) form; normals might not be unit vectors.
     * vn 0.707 0.000 0.707
     * vn ...
     * ...
     * # Parameter space vertices in ( u [,v] [,w] ) form; free form geometry statement ( see below )
     * vp 0.310000 3.210000 2.100000
     * vp ...
     * ...
     * # Polygonal face element (see below)
     * f 1 2 3
     * f 3/1 4/2 5/3
     * f 6/4/1 3/5/3 7/6/5
     * f 7//1 8//2 9//3
     * f ...
     * ...
     *
     *
     * source: https://en.wikipedia.org/wiki/Wavefront_.obj_file
     */
    
    
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
        else if(line.find("vp ") != std::string::npos) {
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

        }
        //if(line.find("f ") != std::string::npos) {
            // f
        //}
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
