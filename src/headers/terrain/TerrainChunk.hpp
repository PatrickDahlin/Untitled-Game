#ifndef _TERRAINCHUNK_HPP_
#define _TERRAINCHUNK_HPP_

#include "core/Common.hpp"
#include "voxel/VoxelData.hpp"
#include "core/Disposable.hpp"
#include "core/Transform.hpp"
#include "graphics/Model.hpp"
#include "graphics/RenderPass.hpp"

class GLTexture;
class ShaderProgram;

class TerrainChunk : public Disposable {
public:
	TerrainChunk(int size, GLTexture* tex, ShaderProgram* shader);
	~TerrainChunk();

	void set_active(bool active);

	bool is_active() const;

	void init();

	void render(RenderPass& pass);
	
	void update(float delta);
	
	void dispose();

	Transform transform;

private:

	bool			active;
	int				size;
	VoxelData		data;

	Model*			mesh;

	GLTexture*		mesh_tex;
	ShaderProgram*	shader;

};

#endif