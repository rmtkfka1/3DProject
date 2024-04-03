#pragma once
#include "Component.h"

class Transform;
class MeshRenderer;
class MonoBeHaviour;
class Camera;

class GameObject : public enable_shared_from_this<GameObject>
{

public:
	GameObject();
	virtual ~GameObject();

	void Init();
	void Awake();
	void Start();
	void Update();
	void LateUpdate();
	void FinalUpdate();

	shared_ptr<Component> GetFixedComponent(COMPONENT_TYPE type);

	shared_ptr<Transform> GetTransform();
	shared_ptr<MeshRenderer> GetMeshRenderer();
	shared_ptr<Camera> GetCamera();


	void AddComponent(shared_ptr<Component> component);

private:
	array<shared_ptr<Component>, FIXED_COMPONENT_COUNT> _components;
	vector<shared_ptr<MonoBeHaviour>> _scripts;


};

