#include "pch.h"
#include "Transform.h"

Transform::Transform() : Component(COMPONENT_TYPE::TRANSFORM)
{

}

Transform::~Transform()
{

}

void Transform::Update()
{

	/* CONST_BUFFER(CONSTANT_BUFFER_TYPE::TRANSFORM)->PushData(&TransformMatirx, sizeof(_transform));*/
}

