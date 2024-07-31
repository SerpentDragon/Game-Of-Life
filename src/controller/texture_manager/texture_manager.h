#pragma once

#include <string>
#include <memory>
#include <filesystem>
#include <unordered_map>
#include <SDL2/SDL_image.h>

namespace fs = std::filesystem;

class TextureManager
{
public:

    // Get the manager instance
    static std::shared_ptr<TextureManager> get_manager();

    // Get the texture by its name
    SDL_Texture* get_texture(const std::string&) const;

    // Set renderer to create textures
    void set_renderer(SDL_Renderer*);

    // Load textures from dirs (the main catalog is img/)
    void load_textures();

    ~TextureManager();

private:

    TextureManager();

    TextureManager(const TextureManager&) = delete;

    TextureManager(TextureManager&&) noexcept = delete;

    TextureManager& operator=(const TextureManager&) = delete;

    TextureManager& operator=(TextureManager&&) noexcept = delete;

    // Load textures from the dir specified
    void load_all_textures_from_dir(const std::string&);

private:

    static std::shared_ptr<TextureManager> manager_;

    // img/
    std::string prefix_;

    SDL_Renderer* renderer_;

    // the dictionary of textures
    mutable std::unordered_map<std::string, SDL_Texture*> textures_;
};