R"(

#version 330 core

layout (location = 0) in vec4 a_Position;
layout (location = 1) in vec4 a_Color;
layout (location = 2) in vec2 a_Coord;

out vec4 v_Color;
out vec2 v_Coord;

uniform mat4 u_Camera = mat4(1.0f);

void main()
{
    gl_Position = u_Camera * a_Position;

    v_Color = a_Color;
    v_Coord = a_Coord;
}

)"