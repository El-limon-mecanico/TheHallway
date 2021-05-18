﻿scene1 = {
    entities = {"defaultCamera", "sceneLight", "Maze"}
}

defaultCamera = {
    Active = true,
    Components = {"Transform", "Camera"},

    Transform = {
        Active = true,
        Position = {25, 750,25},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Active = true,
        Name = "MainCam",
        Background = {1,1,0},
        LookAt = {25,0,25},
        Width = 0,
        Height = 0,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective"
    },
}

sceneLight = {
    Active = true,
    Components = {"Transform", "Light"},

    Transform = {
        Active = true,
        Position = {-10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Light = {
        Active = true,
        LightType = 1,
        DiffuseColor = {1,1,1},
        SpecularColor = {1,1,1},
        Direction = {0,0,0},
        Distance = 100,
        InnerAngle = 30,
        OuterAngle = 90,
        isOn = true
    }
}

Maze = {
    Active = true,
    Components = {"Transform", "MazeCreator", "Lever", "Exit"},

    Transform = {
        Active = true,
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },
    MazeCreator = {
        Active = true,
        Size = 5,
        Holes = 25,
        Levers = 8
    },
    Lever = {

    },
    Exit = {

    }
}