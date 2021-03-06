#include "graphics/ShaderManager.hpp"
#include "core/Files.hpp"
#include "graphics/ShaderProgram.hpp"
#include "core/Common.hpp"

ShaderManager::ShaderManager() : ResourceManager()
{}

ShaderManager::~ShaderManager()
{}

ShaderProgram* ShaderManager::get_shader(std::string vert, std::string frag)
{

	ShaderParams key(vert,frag);
	if(ResourceManager::has_resource(key))
	{
		printf("Found existing shader and returning that in ShaderManager\n");
		return ResourceManager::get_resource(key);
	}
	else
	{
		printf("Loaded new shader in ShaderManager\n");
		printf("%s | %s \n", vert.c_str(), frag.c_str());
		std::string v_src = read_file(vert.c_str());
		std::string f_src = read_file(frag.c_str());
		std::string head = read_file("data/shaders/Shader_Header.glsl");
		ShaderProgram* shader = new ShaderProgram(v_src.c_str(), f_src.c_str(), head.c_str());
		ResourceManager::add_resource(key, shader);
		return shader;
	}
}
