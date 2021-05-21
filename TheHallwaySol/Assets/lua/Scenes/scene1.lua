scene1 = {
    entities = {"defaultCamera", "entidad3", "sceneLight", "Maze", "Player"}
}

entidad1 = {
    Active = true,
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
    Active = true,
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
    Components = {"Transform", "MeshRenderer", "LoopMovement","Rigidbody", "ChasePlayer"},

    Transform = {
        Position = {-10,0,0},
        Scale = {700,700,700},
        Rotation = {90,40,0}
    },

    MeshRenderer = {
        Mesh = "Icosphere.mesh",
    },

    LoopMovement = {
        Speed=10,
        Objectives={{-10,0,0},{51,0,0}, {51,0,51}, {0,0,51}},
        Distance = 15
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = true,
        Static = false,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    },

    ChasePlayer = {
        Speed = 10
    }
}
defaultCamera = {
    Active = true,
    Components = {"Transform", "Camera"},

    Transform = {
        Position = {25,75,25},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
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
    Active = true,
    Components = {"Transform", "MazeCreator"},
    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },
    MazeCreator = {
        Size = 10,
        Holes = 15
    }
}
UI = {
    Active = true,
    Components = {"Text1", "Image1", "Button1"},

    Text1 = {
        Type = "Text",
        Name = "Texto",
        Text = " Esto no es un boton, es solo texto, pero desde lua",
        Position = {0.5,0.05},
        Size = {405,50}
    },

    Image1 = {
        Type = "Image",
        Name = "Cuchao",
        Image = "cuchao.png",
        Position = {0.1,0.6},
        Size = {300,200}
    },
}

Player = {
    Active = true,
    Components = {"Transform", "PlayerMovement", "MeshRenderer"},
    
    Transform = {
        Position = {30,0,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    PlayerMovement = {

    },
    
    MeshRenderer = {
        Mesh = "Suzanne.mesh"
    },
}