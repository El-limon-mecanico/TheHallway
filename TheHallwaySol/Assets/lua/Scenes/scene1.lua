scene1 = {
    entities = {"defaultCamera", "entidad3", "sceneLight"}
}

entidad1 = {
    Active=true,
    Components = {"Transform", "MeshRenderer", "Rigidbody", "Prueba"},

    Transform = {
        Position = {0,5,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MeshRenderer = {
        Mesh = "Suzanne.mesh",
    },

    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = false,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    },

    Prueba = {
        valor1 = 1,
        valor2 = 3,
        valor3 = "Quack"
    }
}

entidad2 = {
    Active=true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {0,-3,0},
        Scale = {5,5,1},
        Rotation = {-90,0,0}
    },

    MeshRenderer = {
        Mesh = "Plane",
    },

    Rigidbody = {
        Type = "Cube",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    }  
}
entidad3 = {
    Active=true,
    Components = {"Transform", "MeshRenderer", "LoopMovement"},

    Transform = {
        Position = {0,-3,0},
        Scale = {1,1,1},
        Rotation = {45,45,0}
    },

    MeshRenderer = {
        Mesh = "Cube",
    },

    LoopMovement = {
        Speed=0.1,
        Objectives={{-10,1,-5},{3,3,3},{-4,-4,-4},{0,0,0}}
    }   
}
defaultCamera = {
    Active=true,
    Components = {"Transform", "Camera"},

    Transform = {
        Position = {10, 10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Name = "MainCam",
        Background = {1,1,0},
        LookAt = {0,0,0},
        Width = 0,
        Height = 0,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective"
    },
}

sceneLight = {
    Active=true,
    Components = {"Transform", "Light"},

    Transform = {
        Position = {-10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Light = {
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
    Components = {"Transform", "MazeCreator"},

    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },
    MazeCreator = {
        Size = 25,
        Holes = 25
    }
}