scene1 = {
    entities = {"defaultCamera", "sceneLight", "Maze", "Player"}
}

defaultCamera = {
    Active = true,
    Components = {"Transform", "Camera"},

    Transform = {
        Active = true,
        Position = {5.75 * 20, 300,5.75*20},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Active = true,
        Name = "MainCam",
        Background = {1,1,0},
        LookAt = {5.75*20,0,5.75*20},
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
    Components = {"Transform", "MazeManager"},

    Transform = {
        Active = true,
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },
    MazeManager = {
        Active = true,
        Size = 5,
        Holes = 200,
        Levers = 1,
        ChargeVel = 5,
        UnchargeVel = 2,
    }
}
Player = 
{
    Active = true,
    Components = {"Transform", "MeshRenderer", "PlayerMovement", "Rigidbody" },
    
    Transform = {
        Active = true,
        Position = {6.5,0,6.5},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },
    MeshRenderer = {
        Mesh = "Suzanne.mesh"
    },
    PlayerMovement = {

    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = false,
        PositionConstrains = {0,1,0},
        RotationConstrains = {1,1,1}
    },

}