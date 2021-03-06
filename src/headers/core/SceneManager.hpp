#ifndef _SCENEMANAGER_HPP_
#define _SCENEMANAGER_HPP_

/*
	Maybe save all loaded scenes in an array that is initialized when
	program starts to reduce loadtimes
*/
#include <vector>

class Scene;
class RenderPass;
class ShaderManager;
class TextureManager;

class SceneManager {
public:
	SceneManager();
	~SceneManager();

	void switch_to_scene(Scene* s);
	// Effect: Switches the currently rendered and updated scene to given scene, NOTE this scene will now be deleted by the manager when manager is disposed
	// Postcond: current scene is the new given scene and the old one is put into loaded_scenes list

	void update(const float delta);
	// Effect: Updates current scene
	// Postond: Current scene is updated to this frame

	void render(RenderPass& pass);
	// Effect: Renders the current scene
	// Postcond: Current scene is queued up for rendering

	void resized_window(int width, int height);
	// Effect: Reloads content for new resolution
	// Postcond: Scenes can be rendered using new resolution without distortion

	void dispose();
	// Effect: Unloads all scenes and disposes them
	// Postcond: All scenes are unloaded and disposed

private:

	int						last_width, last_height;
	Scene*					cur_scene;
	std::vector<Scene*>		loaded_scenes;

	ShaderManager*			shader_manager;
	TextureManager*			texture_manager;

};

#endif