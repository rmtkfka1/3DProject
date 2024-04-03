#pragma once
enum class COMPONENT_TYPE : uint8
{
	TRANSFORM,
	MESH_RENDERER,
	CAMERA,
	MONO_BEHAVIOUR,
	END,
};

enum
{
	FIXED_COMPONENT_COUNT = static_cast<uint8>(COMPONENT_TYPE::END) - 1
};

class GameObject;
class Transform;

class Component
{

public:
	Component(COMPONENT_TYPE type);
	virtual ~Component();

	COMPONENT_TYPE GetComponentType() { return _type; }
	bool IsVaild() { return _gameObject.expired() == false; }

	shared_ptr<GameObject> GetOwner();
	shared_ptr<Transform> GetTransform();



private:
	friend class GameObject;
	void SetOwner(shared_ptr<GameObject> gameObject) { _gameObject = gameObject; }

public:
	virtual void Awake() { }
	virtual void Start() { }
	virtual void Update() { }
	virtual void LateUpdate() { }
	virtual void FinalUpdate() {};


protected:
	COMPONENT_TYPE _type;
	weak_ptr<GameObject> _gameObject;

};

