Slime = {
    Active=true,
    Tag = "Enemy",
    Components = {"Transform", "MeshRenderer","Rigidbody", "MazeRunner"},

    Transform = {
        Position = {-10,0,0},
        Scale = {700,700,700},
        Rotation = {90,40,0}
    },

    MeshRenderer = {
        Mesh = "Icosphere.mesh",
    },

    Rigidbody = {
        Type = "Box",
        Mass = 1,
        Trigger = true,
        Static = false,
        PositionConstrains = {0,1,0},
        RotationConstrains = {1,1,1}
    },

    MazeRunner = {
        Speed = 10,
        Following = false,
        TimeToUpdate = 2.5,
        MaxDistance = 35
    }
}
