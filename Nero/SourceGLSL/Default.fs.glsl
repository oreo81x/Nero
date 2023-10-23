R"(

#version 330 core

in vec4 v_Color;
in vec2 v_Coord;

out vec4 FragColor;

uniform sampler2D u_Texture;

void main()
{
    FragColor = texture(u_Texture, v_Coord) * v_Color;
}

)"